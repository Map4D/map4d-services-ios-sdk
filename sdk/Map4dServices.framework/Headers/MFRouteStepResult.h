//
//  MFRouteStepResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/29/21.
//

#ifndef MFRouteStepResult_h
#define MFRouteStepResult_h

#import "MFLocationComponent.h"
#import "MFRouteDescriptionResult.h"
#import "MFTravelMode.h"
#import "MFLocationComponent.h"

@protocol MFRouteStepResult

@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> distance;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> duration;

@property(nonatomic, readonly, nonnull) MFLocationComponent *startLocation;
@property(nonatomic, readonly, nonnull) MFLocationComponent *endLocation;

@property(nonatomic, readonly, nonnull) NSString *instructions; /* htmlInstructions */
@property(nonatomic, readonly, nonnull) NSString *maneuver;
@property(nonatomic, readonly, nonnull) NSString *encodedPolyline; /* polyline */
@property(nonatomic, readonly, nonnull) NSString *streetName;
@property(nonatomic, readonly) MFTravelMode mode; /* travelMode */

- (NSArray<MFLocationComponent *> *_Nonnull)polyline;

@end

#endif /* MFRouteStepResult_h */
