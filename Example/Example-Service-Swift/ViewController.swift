import UIKit
import Map4dServices
import CoreLocation

class ViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view.
    print("Services version: \(MFServices.version())")
  }
  
  @IBAction func didTapRoute(_ sender: Any) {
    fetchRoute()
  }
  
  @IBAction func didTapDistanceMatrix(_ sender: Any) {
    fetchDistanceMatrix()
    
  }
  
  @IBAction func didTapGeocode(_ sender: Any) {
    geocoding()
  }
  
  @IBAction func didTapAutoSuggest(_ sender: Any) {
    autoSuggest(text: "iot")
  }
  
  @IBAction func didTapPlaceDetail(_ sender: Any) {
    placeDetails()
  }
  
  @IBAction func didTapTextSearch(_ sender: Any) {
    textSearch()
  }
  
  @IBAction func didTapNearbySearch(_ sender: Any) {
    nearbySearch()
  }
  
  @IBAction func didTapViewboxSearch(_ sender: Any) {
    viewboxSearch()
  }
  
  func fetchRoute() {
    let waypoints = [
      MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.067057237614, longitude: 108.198086617386)),
      MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.075225158325, longitude: 108.207924657001))
    ];
    
    let params = MFDirectionsParams(origin: MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.07019138675, longitude: 108.169161586766)),
                                    destination: MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.075367353035, longitude: 108.222074333984)))
    params.waypoints = waypoints
    params.mode = .car
    params.weighting = .shortest
    params.language = .vietnamese
    
    MFDirectionsService().fetchDirections(with: params) { directions, error in
      guard error == nil else {
        print("Error calculating directions: \(error!)")
        return
      }
      
      print("Success \(directions?.routes?.count ?? -1)")
      dump(directions?.routes);
    }
  }
  
  func fetchDistanceMatrix() {
    let origins = [MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.07019138675, longitude: 108.169161586766)),
      MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.067057237614, longitude: 108.198086617386))]
    let destinations = [MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.075225158325, longitude: 108.207924657001)),
      MFLocationComponent(coordinate: CLLocationCoordinate2D(latitude: 16.075367353035, longitude: 108.222074333984))]
    
    let params = MFDistanceMatrixParams(origins: origins, destinations: destinations)
    params.mode = .car
    params.language = .vietnamese
    
    MFDirectionsService().fetchDistanceMatrix(with: params) { matrix, error in
      guard error == nil else {
        print("Error: \(error!)")
        return
      }
      dump(matrix);
      print("---row: \(matrix?.rows?.count ?? 0)")
    }
  }
  
  func geocoding() {
    let service = MFPlacesService()
    let params = MFGeocodeParams(location: MFLocationComponent(latitude: 16.024634, longitude: 108.209217))
    params.address = "31 Lê Văn Duyệt, Phường Nại Hiên Đông, Quận Sơn Trà, Thành Phố Đà Nẵng"
    params.viewbox = MFViewboxComponent(southwest: CLLocationCoordinate2D(latitude: 16.056453967981348, longitude: 108.19387435913086),
                                         northeast: CLLocationCoordinate2D(latitude: 16.093031550262133, longitude: 108.25927734375))
    
    service.geocoding(with: params) { places, error in
      if error != nil {
        print("Geocode Error: \(error!)")
        return
      }
      guard let places = places else {
        print("Result is NIL")
        return
      }
      dump(places)
      for place in places {
        print("Place: \(place.id ?? "")")
        print("Name: \(place.name)")
        print("Address: \(place.address)")
        print("Location:\(place.location)")
      }
    }
  }
  
  func autoSuggest(text: String) {
    let service = MFPlacesService()
    let params = MFSuggestionParams(text: text)
    
    service.fetchSuggestion(with: params) { places, error in
      if error != nil {
        print("AutoSuggest Error: \(error!)")
        return
      }
      
      guard places != nil else {
        print("Result is NIL")
        return
      }
      
      for place in places! {
        print("Place: \(place.id ?? ""), name: \(place.name), address: \(place.address), location:\(place.location)")
      }
    }
  }
  
  func textSearch() {
    let service = MFPlacesService()
    let params = MFTextSearchParams(text: "abc")
    
    service.searchText(with: params) { places, error in
      if error != nil {
        print("Text search error: \(error!)")
        return
      }
      guard places != nil else { return }
      for place in places! {
        print(dump(place))
      }
    }
  }
  
  func placeDetails() {
    let service = MFPlacesService()
    service.fetchPlaceDetail(withPlaceId: "5d0de3c7595b752b54a9a005") { place, error in
      if error != nil {
        print("Get place details error: \(error!)")
        return
      }
      dump(place)
    }
  }
  
  func nearbySearch() {
    let service = MFPlacesService()
    let params = MFNearbySearchParams(location: MFLocationComponent(latitude: 16.0938083, longitude: 108.2285675), radius: 5000, types: ["cafe"])

    service.searchNearby(with: params) { places, error in
      if error != nil {
        print("Nearby search error: \(error!)")
        return
      }
      guard let places = places else { return }
      for place in places {
        print(dump(place))
      }
    }
  }
  
  func viewboxSearch() {
    let service = MFPlacesService()
    let params = MFViewboxSearchParams(viewbox: MFViewboxComponent(southwest: CLLocationCoordinate2D(latitude: 16.056453967981348, longitude: 108.19387435913086),
                                                                    northeast: CLLocationCoordinate2D(latitude: 16.093031550262133, longitude: 108.25927734375)),
                                        text: "cafe")
    
    service.searchViewbox(with: params) { places, error in
      if error != nil {
        print("Viewbox search error: \(error!)")
        return
      }
      guard let places = places else { return }
      for place in places {
        print(dump(place))
      }
    }
  }
}

