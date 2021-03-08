//
//  ViewController.m
//  Example-Service-Objc
//
//  Created by iMacbook on 3/1/21.
//

#import "ViewController.h"
#import <CoreLocation/CoreLocation.h>
@import Map4dServices;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view.
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
  MFWaypoint * waypoints1 = [[MFWaypoint alloc] initWithCoordinate:CLLocationCoordinate2DMake(16.07019138675, 108.169161586766) name:@""];
  MFWaypoint * waypoints2 = [[MFWaypoint alloc] initWithCoordinate:CLLocationCoordinate2DMake(16.067057237614, 108.198086617386) name:@""];
  NSArray* arrs = [[NSArray alloc] initWithObjects:waypoints1, waypoints2, nil];
  
  MFDirectionOptions* request = [[MFDirectionOptions alloc] init];
  request.waypoints = arrs;
  MFDirectionService* directionService = [[MFDirectionService alloc] init];
  [directionService routeWithOptions:request completion:^(NSArray<MFRoute *> * routes, id<MFServiceError> err) {
    NSUInteger count = routes.count;
    for (int i = 0; i < count; i++) {
      NSLog(@"-------------------------------------------");
      MFRoute * route = [routes objectAtIndex:i];
      NSLog(@"%@", route.summary);
      NSArray * overviewCoordinates = route.overviewCoordinates;
      for (int j = 0; j < overviewCoordinates.count; j++) {
        id overviewCoordinate = [overviewCoordinates objectAtIndex:j];
        CLLocationCoordinate2D loc;
        [overviewCoordinate getValue:&loc];
        NSLog(@"lat: %f lng: %f", loc.latitude, loc.longitude);
      }
    }
  }];
}

-(void) distanceMatrix {
  MFWaypoint *origin1 = [[MFWaypoint alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.07019138675, 108.169161586766) name:@""];
  MFWaypoint *origin2 = [[MFWaypoint alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.067057237614, 108.198086617386) name:@""];
  MFWaypoint *destination1 = [[MFWaypoint alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.075225158325, 108.207924657001) name:@""];
  MFWaypoint *destination2 = [[MFWaypoint alloc] initWithCoordinate: CLLocationCoordinate2DMake(16.075367353035, 108.222074333984) name:@""];
  NSArray *origins = [[NSArray alloc] initWithObjects: origin1, origin2, nil];
  NSArray *destinations = [[NSArray alloc] initWithObjects: destination1, destination2, nil];
  
  MFDistanceMatrixOptions *options = [[MFDistanceMatrixOptions alloc] initWithOrigins:origins destinations:destinations];
  [options setMode: MFTravelModeCar];
  [options setLanguage: @"vi"];
  MFDistanceMatrixService *distanceMatrixService = [[MFDistanceMatrixService alloc] init];
  [distanceMatrixService getDistanceMatrixWithOptions:options completion:^(MFDistanceMatrix * distanceMatrix, id<MFServiceError> error) {
    NSInteger rowCount = distanceMatrix.rows.count;
    NSLog(@"-------------------------------------------");
    for (int i = 0; i < rowCount; i++) {
      NSInteger originCount = [[[[distanceMatrix rows] objectAtIndex: i] elements] count];
      for (int j = 0; j < originCount; j++) {
        NSString * status = [[[[[distanceMatrix rows] objectAtIndex: i] elements] objectAtIndex: j] status];
        NSString * distance = [[[[[[distanceMatrix rows] objectAtIndex: i] elements] objectAtIndex: j] distance] text];
        NSString * duration = [[[[[[distanceMatrix rows] objectAtIndex: i] elements] objectAtIndex: j] duration] text];
        NSLog(@"status: %@ - distance: %@ - duration: %@", status, distance, duration);
      }
    }
  }];
}

-(void) geocoding {
  MFGeocodeService *service = [[MFGeocodeService alloc] init];
  MFGeocodeOptions *options = [[MFGeocodeOptions alloc] init];
  
  CLLocation *location = [[CLLocation alloc] initWithLatitude: 16.024634 longitude: 108.209217];
  NSString *address = @"31 Lê Văn Duyệt, Phường Nại Hiên Đông, Quận Sơn Trà, Thành Phố Đà Nẵng";
  CLLocation *southWest = [[CLLocation alloc] initWithLatitude: 16.056453967981348 longitude: 108.19387435913086];
  CLLocation *northEast = [[CLLocation alloc] initWithLatitude: 16.093031550262133 longitude: 108.25927734375];
  
  [options setLocation: location];
  [options setAddress: address];
  [options setSouthWest: southWest];
  [options setNorthEast: northEast];
  [service geocodeWithOptions:options completion:^(NSArray<MFPlace *> * places, id<MFServiceError> error) {
    
    if (error != nil) {
      NSLog(@"AutoSuggest Error: %@", error);
      return;
    }
    if (places == nil) {
      NSLog(@"Places is NIL");
      return;
    }
    for (int i = 0; i < places.count; i++) {
      MFPlace* place = [places objectAtIndex:i];
      NSLog(@"Place: %@, %@, %@, (%f,%f)", place.id, place.types, place.address, place.location.latitude, place.location.longitude);
    }
  }];
}

- (void) autoSuggest:(NSString*) text {
  MFAutocompleteService* service = [[MFAutocompleteService alloc] init];
  MFQueryAutocompletionOptions* options = [[MFQueryAutocompletionOptions alloc] initWithText:text location:nil];
  
  [service getQueryPredictionsWithOptions:options completion:^(NSArray<MFPlace *> * places, id<MFServiceError> error) {
    if (error != nil) {
      NSLog(@"AutoSuggest Error: %@", error);
      return;
    }
    if (places == nil) {
      NSLog(@"Places is NIL");
      return;
    }
    
    for (int i = 0; i < places.count; i++) {
      MFPlace* place = [places objectAtIndex:i];
      NSLog(@"Place: %@, %@, %@, %f-%f", place.id, place.types, place.address, place.location.latitude, place.location.longitude);
    }
  }];
}

- (void)getPlaceDetails:(NSString*)placeId {
  MFPlacesService* service = [[MFPlacesService alloc] init];
  [service getDetailsWithPlaceId:placeId completion:^(MFPlaceDetails * place, id<MFServiceError> err) {
    if (err != nil) {
      NSLog(@"Get place details error: %@", err);
      return;
    }
    NSLog(@"Place details: %@", place);
    NSArray<MFPlacePhotoInfo*>* photos = place.photos;
    for (int i = 0; i < [photos count]; i++) {
      NSLog(@"Photo %d: %s", i, [[photos objectAtIndex:i].url UTF8String]);
    }
  }];
}

- (void)getTextSearch:(NSString*) text {
  MFPlacesService* service = [[MFPlacesService alloc] init];
  MFTextSearchOptions* options = [[MFTextSearchOptions alloc] initWithText:text];
  [service textSearchWithOptions:options completion:^(NSArray<MFPlace *> * places, id<MFServiceError> error) {
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
  MFNearbySearchOptions* options = [[MFNearbySearchOptions alloc] initWithLocation:CLLocationCoordinate2DMake(16.036461, 108.218159) radius:500];
  options.text = @"cafe";
  [service nearbySearchWithOptions:options completion:^(NSArray<MFPlace *> * places, id<MFServiceError> error) {
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
  MFViewboxSearchOptions* options = [[MFViewboxSearchOptions alloc] initWithSouthWest:southWest northEast:northEast];
  options.types = [[NSArray alloc] initWithObjects:@"cafe", nil];
  
  [service viewboxSearchWithOptions:options completion:^(NSArray<MFPlace *> * places, id<MFServiceError> error) {
    if (error != nil) {
      NSLog(@"Viewbox Search error: %@", error);
      return;
    }
    for (int i = 0; i < [places count]; i++) {
      MFPlace* place = [places objectAtIndex:i];
      NSLog(@"Place [%d] : %@", i, place);
    }
  }];
}

@end
