//
//  MFRouteResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/29/21.
//

#ifndef MFRouteResult_h
#define MFRouteResult_h

#import "MFRouteLegResult.h"
#import "MFRouteDescriptionResult.h"
#import "MFLocationComponent.h"

@protocol MFRouteResult

@property(nonatomic, readonly, nonnull) NSArray<id<MFRouteLegResult>> *legs;
@property(nonatomic, readonly, nonnull) NSString *encodedPolyline; /* overviewPolyline */
@property(nonatomic, readonly, nonnull) NSString *summary;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> distance;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> duration;
@property(nonatomic, readonly, nonnull) NSArray<MFLocationComponent *> *snappedLocations; /* snappedWaypoints */

- (NSArray<MFLocationComponent *> *_Nonnull)polyline;

@end

#endif /* MFRouteResult_h */
