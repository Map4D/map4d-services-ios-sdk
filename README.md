# Map4D Services SDK

> Map4D Services SDK for iOS, written in C/C++, Objective-C.

[![CocoaPods](https://map4d.vn/Content/Client/img/Untitled-1_0000_Right-Mockup--phone-demo-copy.png)](https://map4d.vn) 


## Installation

Use [CocoaPods](https://cocoapods.org).

1. Update your cocoapods local repo
```shell
pod repo update
```

2. Add to Podfile
```shell
pod 'Map4dServices'
```

## Provide access key

Edit `Info.plist` and add Map4d services access key

```xml
<key>Map4dServicesAccessKey</key>
<string>YOUR_SERVICES_ACCESS_KEY</string>
```

## Using

### 1. Direction service

```swift
let options = MFDirectionOptions()
options.origin = CLLocation(latitude: 16.024634, longitude: 108.209217)
options.destination = CLLocation(latitude: 16.020179, longitude: 108.211212)
let service = MFDirectionService()
service.route(options: options) { (routes, error) in
    // ...
}
```

### 2. Distance Matrix service

```swift
let origins = [
    MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.07019138675, longitude: 108.169161586766)),
    MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.06705723761, longitude: 108.198086617386))
]
let destinations = [
    MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.075225158325, longitude: 108.207924657001)),
    MFWaypoint(coordinate: CLLocationCoordinate2D(latitude: 16.075367353035, longitude: 108.222074333984))
]

let options = MFDistanceMatrixOptions(origins: origins, destinations: destinations)
options.mode = .car
options.language = "vi"

MFDistanceMatrixService().getDistanceMatrix(options: options) { response, error in
    // ...
}
```

### 3. Autocomplete service

```swift
let service = MFAutocompleteService()
let options = MFQueryAutocompletionOptions(text: "Landmark")

service.getQueryPredictions(options: options) { (places, error) in
    // ...
}
```

### 4. GeoCode service

```swift
let service = MFGeocodeService()
let options = MFGeocodeOptions()
options.location = CLLocation(latitude: 16.024634, longitude: 108.209217)
options.address = "31 Lê Văn Duyệt, Phường Nại Hiên Đông, Quận Sơn Trà, Thành Phố Đà Nẵng"
options.southWest = CLLocation(latitude: 16.056453967981348, longitude: 108.19387435913)
options.northEast = CLLocation(latitude: 16.093031550262133, longitude: 108.25927734375)

service.geocode(options: options){ places, error in
    // ...
}
```

### 5. Place services

#### 5.1 Place details service

```swift
let service = MFPlacesService()
service.getDetails(placeId: "5d0de3c7595b752b54a9a005") { (place, error) in
    // ...
}
```

#### 5.2 Text search service

```swift
let service = MFPlacesService()
let options = MFTextSearchOptions(text: "Landmark")
service.textSearch(options: options) { (places, error) in
    // ...
}
```

#### 5.3 Nearby search service

```swift
let service = MFPlacesService()
let options = MFNearbySearchOptions(location: CLLocationCoordinate2D(latitude: 16.0938083, longitude: 108.2285675), radius: 5000)
options.types = ["cafe"]
service.nearbySearch(options: options) { (places, error) in
    // ...
}
```

#### 5.4 Viewbox search service

```swift
let service = MFPlacesService()
let options = MFViewboxSearchOptions(southWest: CLLocationCoordinate2D(latitude: 16.056453967981348, longitude: 108.19387435913),
                                     northEast: CLLocationCoordinate2D(latitude: 16.093031550262133, longitude: 108.25927734375))
options.text = "cafe"
service.viewboxSearch(options: options) { (places, error) in
    // ...
}
```

License
-------

Copyright (C) 2021 IOT Link Ltd. All Rights Reserved.
