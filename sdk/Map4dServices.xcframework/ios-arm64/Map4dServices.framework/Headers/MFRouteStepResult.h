//
//  MFRouteStepResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFRouteStepResult_h
#define MFRouteStepResult_h

#import "MFLocationComponent.h"
#import "MFRouteDescriptionResult.h"
#import "MFTravelMode.h"
#import "MFLocationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFRouteStepResult : NSObject

@property(nonatomic, readonly) MFRouteDescriptionResult *distance;
@property(nonatomic, readonly) MFRouteDescriptionResult *duration;

@property(nonatomic, readonly) MFLocationComponent *startLocation;
@property(nonatomic, readonly) MFLocationComponent *endLocation;

@property(nonatomic, readonly) NSString *instructions; /* htmlInstructions */
@property(nonatomic, readonly) NSString *maneuver;
@property(nonatomic, readonly) NSString *encodedPolyline; /* polyline */
@property(nonatomic, readonly) NSString *streetName;
@property(nonatomic, readonly) MFTravelMode mode; /* travelMode */

- (instancetype)init NS_UNAVAILABLE;

- (NSArray<MFLocationComponent *> *)polyline;

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteStepResult_h */
