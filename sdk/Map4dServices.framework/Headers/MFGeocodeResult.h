//
//  MFGeocodeResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
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
@property(nonatomic, readonly) NSArray<NSString *> *types;
@property(nonatomic, readonly, nullable) NSArray<MFPlaceAddressComponentResult *> *addressComponents;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFGeocodeResult_h */
