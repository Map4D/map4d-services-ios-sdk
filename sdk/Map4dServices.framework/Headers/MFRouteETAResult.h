//
//  MFRouteETAResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/31/21.
//

#ifndef MFRouteETAResult_h
#define MFRouteETAResult_h

#import "MFLocationComponent.h"
#import "MFRouteDescriptionResult.h"
#import "MFLocationComponent.h"

@protocol MFRouteETAResult

@property(nonatomic, readonly, nonnull) MFLocationComponent *location;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> distance;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> duration;
@property(nonatomic, readonly, nonnull) NSString *encodedPolyline;

- (NSArray<MFLocationComponent *> *_Nonnull)polyline;

@end

#endif /* MFRouteETAResult_h */
