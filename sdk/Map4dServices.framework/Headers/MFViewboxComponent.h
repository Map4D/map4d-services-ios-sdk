//
//  MFViewboxComponent.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFViewboxComponent_h
#define MFViewboxComponent_h

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFViewboxComponent : NSObject

@property(nonatomic, readonly) CLLocationCoordinate2D southwest;
@property(nonatomic, readonly) CLLocationCoordinate2D northeast;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithSouthwest:(CLLocationCoordinate2D)southwest northeast:(CLLocationCoordinate2D)northeast;

@end

NS_ASSUME_NONNULL_END

#endif /* MFViewboxComponent_h */
