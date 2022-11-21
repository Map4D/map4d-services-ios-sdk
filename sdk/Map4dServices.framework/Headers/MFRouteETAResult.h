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

NS_ASSUME_NONNULL_BEGIN

@interface MFRouteETAResult : NSObject

@property(nonatomic, readonly) MFLocationComponent *location;
@property(nonatomic, readonly) MFRouteDescriptionResult *distance;
@property(nonatomic, readonly) MFRouteDescriptionResult *duration;
@property(nonatomic, readonly) NSString *encodedPolyline;

- (instancetype)init NS_UNAVAILABLE;

- (NSArray<MFLocationComponent *> *)polyline;

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteETAResult_h */
