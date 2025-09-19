//
//  MFGeocodeResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFGeocodeResult_h
#define MFGeocodeResult_h

#import "MFLocationComponent.h"
#import "MFPlaceAddressComponentResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFGeocodeResult : NSObject

@property(nonatomic, readonly, nullable) NSString *id;
@property(nonatomic, readonly) MFLocationComponent *location;
@property(nonatomic, readonly) NSString *name;
@property(nonatomic, readonly) NSString *address;
@property(nonatomic, readonly) NSString *oldAddress;
@property(nonatomic, readonly) NSArray<NSString *> *types;
@property(nonatomic, readonly, nullable) NSArray<MFPlaceAddressComponentResult *> *addressComponents;
@property(nonatomic, readonly, nullable) NSArray<MFPlaceAddressComponentResult *> *oldAddressComponents;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFGeocodeResult_h */
