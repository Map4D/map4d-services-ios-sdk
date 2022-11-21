//
//  MFGraphRouteResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFGraphRouteResult_h
#define MFGraphRouteResult_h

#import <CoreLocation/CoreLocation.h>
#import "MFRouteDescriptionResult.h"
#import "MFLocationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFGraphRouteResult : NSObject

@property(nonatomic, readonly) NSString *id;
@property(nonatomic, readonly) MFRouteDescriptionResult *distance;
@property(nonatomic, readonly) MFRouteDescriptionResult *duration;
@property(nonatomic, readonly) NSString *encodedPolyline; /* polyline */
//@property(nonatomic, readonly) NSString *status;//TODO: status

- (instancetype)init NS_UNAVAILABLE;

- (NSArray<MFLocationComponent *> *)polyline;

@end

NS_ASSUME_NONNULL_END

#endif /* MFGraphRouteResult_h */
