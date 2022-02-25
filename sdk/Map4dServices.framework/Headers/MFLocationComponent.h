//
//  MFLocationComponent.h
//  Map4dServices
//
//  Created by Huy Dang on 1/2/22.
//

#ifndef MFLocationComponent_h
#define MFLocationComponent_h

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFLocationComponent : NSObject

@property(nonatomic, readonly) CLLocationCoordinate2D coordinate;

@property(nonatomic, readonly, nullable) NSString *alias;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate alias:(NSString *_Nullable)alias;

- (instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;

- (instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude alias:(NSString *_Nullable)alias;

- (CLLocationDegrees)latitude;

- (CLLocationDegrees)longitude;

- (BOOL)isValidCoordinate;

@end

NS_ASSUME_NONNULL_END

#endif /* MFLocationComponent_h */
