//
//  ViewController.m
//  Example-Service-Objc
//
//  Created by iMacbook on 3/1/21.
//

#import "ViewController.h"
#import <Map4dServices/Map4dServices.h>

@import Map4dServices;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  NSLog(@"Services version: %@", MFServices.version);
}

- (IBAction)didTapRoute:(id)sender {
  [self direction];
}

- (IBAction)didTapDistanceMatrix:(id)sender {
  [self distanceMatrix];
}

- (IBAction)didTapGeocode:(id)sender {
  [self geocoding];
}

- (IBAction)didTapAutoSuggest:(id)sender {
  [self autoSuggest:@"abc"];
}

- (IBAction)didTapPlaceDetail:(id)sender {
  [self getPlaceDetails:@"5d0de3c7595b752b54a9a005"];
}

- (IBAction)didTapTextSearch:(id)sender {
  [self getTextSearch:@"abc"];
}

- (IBAction)didTapNearbySearch:(id)sender {
  [self nearbySearch];
}

- (IBAction)didTapViewboxSearch:(id)sender {
  [self viewboxSearch];
}

- (void) direction {
  MFLocationComponent * waypoints1 = [[MFLocationComponent alloc] initWithCoordinate:CLLocationCoordinate2DMake(16.07019138675, 108.169161586766)];
  MFLocationComponent * waypoints2 = [[MFLocationComponent alloc] initWithCoordinate:CLLocationCoordinate2DMake(16.067057237614, 108.198086617386)];
  
  MFDirectionsParams* params = [[MFDirectionsParams alloc] initWithOrigin:waypoints1 destination:waypoints2];
  MFDirectionsService* directionService = [[MFDirectionsService alloc] init];
  [directionService fetchDirectionsWithParams:params completionHandler:^(id<MFDirectionsResult> _Nullable result, id<MFServiceError> _Nullable err) {
    NSArray<id<MFRouteResult>> *routes = result.routes;
    NSUInteger count = result.routes.count;
    for (int i = 0; i < count; i++) {
      NSLog(@"-------------------------------------------");
      id<MFRouteResult> route = [routes objectAtIndex:i];
      NSLog(@"%@", route.summary);
      NSArray<MFLocationComponent *> *overviewCoordinates = route.snappedLocations;
      for (int j = 0; j < overviewCoordinates.count; j++) {
        MFLocationComponent *overviewCoordinate = [overviewCoordinates objectAtIndex:j];
        CLLocationCoordinate2D loc = overviewCoordinate.coordinate;
        NSLog(@"lat: %f lng: %f", loc.latitude, loc.longitude);
      }
    }
  }];
}

-(void) distanceMatrix {
  MFLocationComponent *origin1 = [[MFLocationComponent alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.07019138675, 108.169161586766)];
  MFLocationComponent *origin2 = [[MFLocationComponent alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.067057237614, 108.198086617386)];
  MFLocationComponent *destination1 = [[MFLocationComponent alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.075225158325, 108.207924657001)];
  MFLocationComponent *destination2 = [[MFLocationComponent alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.075367353035, 108.222074333984)];
  NSArray *origins = [[NSArray alloc] initWithObjects: origin1, origin2, nil];
  NSArray *destinations = [[NSArray alloc] initWithObjects: destination1, destination2, nil];
  
  MFDistanceMatrixParams *options = [[MFDistanceMatrixParams alloc] initWithOrigins:origins destinations:destinations];
  [options setMode: MFTravelModeCar];
  [options setLanguage:MFLanguageResultVietnamese];
  
  MFDirectionsService *distanceMatrixService = [[MFDirectionsService alloc] init];
  [distanceMatrixService fetchDistanceMatrixWithParams:options completionHandler:^(id<MFDistanceMatrixResult>  _Nullable distanceMatrix, id<MFServiceError>  _Nullable error) {
    NSInteger rowCount = distanceMatrix.rows.count;
    NSLog(@"-------------------------------------------");
    for (int i = 0; i < rowCount; i++) {
      NSInteger originCount = [[[[distanceMatrix rows] objectAtIndex: i] elements] count];
      for (int j = 0; j < originCount; j++) {
        NSString * distance = [[[[[[distanceMatrix rows] objectAtIndex: i] elements] objectAtIndex: j] distance] text];
        NSString * duration = [[[[[[distanceMatrix rows] objectAtIndex: i] elements] objectAtIndex: j] duration] text];
        NSLog(@"distance: %@ - duration: %@", distance, duration);
      }
    }
  }];
}

-(void) geocoding {
  MFPlacesService *service = [[MFPlacesService alloc] init];
  MFGeocodeParams *params = [[MFGeocodeParams alloc] initWithLocation:[[MFLocationComponent alloc] initWithLatitude:16.024634 longitude:108.209217]];
  params.address = @"31 Lê Văn Duyệt, Phường Nại Hiên Đông, Quận Sơn Trà, Thành Phố Đà Nẵng";
  
  CLLocation *southWest = [[CLLocation alloc] initWithLatitude: 16.056453967981348 longitude: 108.19387435913086];
  CLLocation *northEast = [[CLLocation alloc] initWithLatitude: 16.093031550262133 longitude: 108.25927734375];
  params.viewbox = [[MFViewboxComponent alloc] initWithSouthwest:southWest.coordinate northeast:northEast.coordinate];
  
  [service geocodingWithParams:params completionHandler:^(NSArray<id<MFGeocodeResult>> * _Nullable places, id<MFServiceError>  _Nullable error) {
    if (error != nil) {
      NSLog(@"Error: %@", error);
      return;
    }
    if (places == nil) {
      NSLog(@"Places is NIL");
      return;
    }
    for (int i = 0; i < places.count; i++) {
      id<MFGeocodeResult> place = [places objectAtIndex:i];
      NSLog(@"Place: %@, %@, %@, (%f,%f)", place.id, place.types, place.address, place.location.latitude, place.location.longitude);
    }
  }];
}

- (void) autoSuggest:(NSString*)text {
  MFPlacesService* service = [[MFPlacesService alloc] init];
  MFSuggestionParams* params = [[MFSuggestionParams alloc] initWithText:text];
  
  [service fetchSuggestionWithParams:params completionHandler:^(NSArray<id<MFSuggestionResult>> * _Nullable places, id<MFServiceError>  _Nullable error) {
    if (error != nil) {
      NSLog(@"AutoSuggest Error: %@", error);
      return;
    }
    if (places == nil) {
      NSLog(@"Places is NIL");
      return;
    }
    
    for (int i = 0; i < places.count; i++) {
      id<MFSuggestionResult> place = [places objectAtIndex:i];
      NSLog(@"Place: %@, %@, %@, %f-%f", place.id, place.types, place.address, place.location.latitude, place.location.longitude);
    }
  }];
}

- (void)getPlaceDetails:(NSString*)placeId {
  MFPlacesService* service = [[MFPlacesService alloc] init];
  [service fetchPlaceDetailWithPlaceId:placeId completionHandler:^(id<MFPlaceDetailResult>  _Nullable place, id<MFServiceError>  _Nullable err) {
    if (err != nil) {
      NSLog(@"Get place details error: %@", err);
      return;
    }
    NSLog(@"Place details: %@", place);
    NSArray<id<MFPlacePhotoResult>> *photos = place.photos;
    for (int i = 0; i < [photos count]; i++) {
      NSLog(@"Photo %d: %s", i, [[photos objectAtIndex:i].url UTF8String]);
    }
  }];
}

- (void)getTextSearch:(NSString*) text {
  MFPlacesService* service = [[MFPlacesService alloc] init];
  MFTextSearchParams* params = [[MFTextSearchParams alloc] initWithText:text];
  
  [service searchTextWithParams:params completionHandler:^(NSArray<id<MFPlaceResult>> * _Nullable places, id<MFServiceError>  _Nullable error) {
    if (error != nil) {
      NSLog(@"Text Search error: %@", error);
      return;
    }
    for (int i = 0; i < [places count]; i++) {
      NSLog(@"Place [%d] : %@", i, [places objectAtIndex:i]);
    }
  }];
}

- (void)nearbySearch {
  MFPlacesService* service = [[MFPlacesService alloc] init];
  MFNearbySearchParams* params = [[MFNearbySearchParams alloc] initWithLocation:[[MFLocationComponent alloc] initWithCoordinate:CLLocationCoordinate2DMake(16.036461, 108.218159)]
                                                                          radius:500
                                                                            text:@"cafe"];
  [service searchNearbyWithParams:params completionHandler:^(NSArray<id<MFPlaceResult>> * _Nullable places, id<MFServiceError>  _Nullable error) {
    if (error != nil) {
      NSLog(@"Nearby Search error: %@", error);
      return;
    }
    for (int i = 0; i < [places count]; i++) {
      NSLog(@"Place [%d] : %@", i, [places objectAtIndex:i]);
    }
  }];
}

- (void)viewboxSearch {
  MFPlacesService* service = [[MFPlacesService alloc] init];
  CLLocationCoordinate2D southWest = CLLocationCoordinate2DMake(16.056453967981348, 108.19387435913);
  CLLocationCoordinate2D northEast = CLLocationCoordinate2DMake(16.093031550262133, 108.25927734375);
  MFViewboxComponent *viewbox = [[MFViewboxComponent alloc] initWithSouthwest:southWest northeast:northEast];
  MFViewboxSearchParams* options = [[MFViewboxSearchParams alloc] initWithViewbox:viewbox types:[[NSArray alloc] initWithObjects:@"cafe", nil]];
  
  [service searchViewboxWithParams:options completionHandler:^(NSArray<id<MFPlaceResult>> * _Nullable places, id<MFServiceError>  _Nullable error) {
    if (error != nil) {
      NSLog(@"Viewbox Search error: %@", error);
      return;
    }
    for (int i = 0; i < [places count]; i++) {
      id<MFPlaceResult> place = [places objectAtIndex:i];
      NSLog(@"Place [%d] : %@", i, place);
    }
  }];
}

@end
