# Map4D Services SDK
[![map4d](https://img.shields.io/badge/map4d-services-orange)](https://map4d.vn/)
[![platform](https://img.shields.io/cocoapods/p/Map4dServices)](https://www.apple.com/ios/)
[![cocoapods](https://img.shields.io/cocoapods/v/Map4dServices)](https://cocoapods.org/pods/Map4dServices)

> Map4D Services SDK brings the [Map4D API Services](https://docs.map4d.vn/map4d-service/api/) for your iOS Application

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

## Example

Get place detail

<!-- tabs:start -->
#### ** Swift **

```swift
let service = MFPlacesService()
service.fetchPlaceDetail(withPlaceId: "60dd3850f81cb14bc880ed52") { result, error in
  guard let result = result else {
    dump(error)
    return
  }
  print("name \(result.name)")
}
```

#### ** Objective C **

```objc
MFPlacesService* service = [[MFPlacesService alloc] init];
[service fetchPlaceDetailWithPlaceId:placeId completionHandler:^(id<MFPlaceDetailResult> _Nullable result, id<MFServiceError>  _Nullable error) {
  if (error != nil) {
    NSLog(@"code: %@, message: %@", error.code, error.message);
  }
  else {
    NSLog(@"name: %@", result.name);
  }
}];
```
<!-- tabs:end -->

License
-------

Copyright (C) 2022 IOT Link Ltd. All Rights Reserved.
