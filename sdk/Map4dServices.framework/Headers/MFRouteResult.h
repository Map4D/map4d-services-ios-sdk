//
//  MFRouteResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFRouteResult_h
#define MFRouteResult_h

#import "MFRouteLegResult.h"
#import "MFRouteDescriptionResult.h"
#import "MFLocationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFRouteResult : NSObject

@property(nonatomic, readonly) NSArray<MFRouteLegResult *> *legs;
@property(nonatomic, readonly) NSString *encodedPolyline; /* overviewPolyline */
@property(nonatomic, readonly) NSString *summary;
@property(nonatomic, readonly) MFRouteDescriptionResult *distance;
@property(nonatomic, readonly) MFRouteDescriptionResult *duration;
@property(nonatomic, readonly) NSArray<MFLocationComponent *> *snappedLocations; /* snappedWaypoints */

- (instancetype)init NS_UNAVAILABLE;

- (NSArray<MFLocationComponent *> *)polyline;

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteResult_h */
