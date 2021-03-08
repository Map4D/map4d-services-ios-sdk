import UIKit
import Map4dServices
import CoreLocation

class ViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view.
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
      MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.07019138675, longitude: 108.169161586766)),
      MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.067057237614, longitude: 108.198086617386)),
      MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.075225158325, longitude: 108.207924657001)),
      MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.075367353035, longitude: 108.222074333984))
    ];
    
    let options = MFDirectionOptions()
    options.waypoints = waypoints
    options.mode = .car
    options.weighting = .shortest
    options.language = "vi"
    
    MFDirectionService().route(options: options) { (routes, error) in
      
      guard error == nil else {
        print("Error calculating directions: \(error!)")
        return
      }
      
      print("Success \(routes?.count ?? -1)")
      dump(routes);
    }
  }
  
  func fetchDistanceMatrix() {
    let origins = [MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.07019138675, longitude: 108.169161586766)),
      MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.067057237614, longitude: 108.198086617386))]
    let destinations = [MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.075225158325, longitude: 108.207924657001)),
      MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.075367353035, longitude: 108.222074333984))]
    
    let options = MFDistanceMatrixOptions(origins: origins, destinations: destinations)
    options.mode = .car
    options.language = "vi"
    
    MFDistanceMatrixService().getDistanceMatrix(options: options) { response, error in
      guard error == nil else {
        print("Error: \(error!)")
        return
      }
      dump(response);
      print("---row: \(response?.rows?.count ?? 0)")
    }
  }
  
  func geocoding() {
    let service = MFGeocodeService()
    let options = MFGeocodeOptions()
    
    options.location = CLLocation(latitude: 16.024634, longitude: 108.209217)
    options.address = "31 Lê Văn Duyệt, Phường Nại Hiên Đông, Quận Sơn Trà, Thành Phố Đà Nẵng"
    options.southWest = CLLocation(latitude: 16.056453967981348, longitude: 108.19387435913086)
    options.northEast = CLLocation(latitude: 16.093031550262133, longitude: 108.25927734375)
    
    service.geocode(options: options){ places, error in
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
    let service = MFAutocompleteService()
    let options = MFQueryAutocompletionOptions(text: text)
    
    service.getQueryPredictions(options: options) { (places, error) in
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
    let options = MFTextSearchOptions(text: "abc")
    service.textSearch(options: options) { (places, error) in
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
    service.getDetails(placeId: "5d0de3c7595b752b54a9a005") { (place, error) in
      if error != nil {
        print("Get place details error: \(error!)")
        return
      }
      dump(place)
    }
  }
  
  func nearbySearch() {
    let service = MFPlacesService()
    let options = MFNearbySearchOptions(location: CLLocationCoordinate2D(latitude: 16.0938083, longitude: 108.2285675), radius: 5000)
    options.types = ["cafe"]
    service.nearbySearch(options: options) { (places, error) in
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
    let options = MFViewboxSearchOptions(southWest: CLLocationCoordinate2D(latitude: 16.056453967981348, longitude: 108.19387435913086),
                                         northEast: CLLocationCoordinate2D(latitude: 16.093031550262133, longitude: 108.25927734375))
    options.text = "cafe"
    service.viewboxSearch(options: options) { (places, error) in
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

