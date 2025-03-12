//
//  MFViewboxComponent.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
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
