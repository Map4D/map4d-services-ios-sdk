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

@protocol MFGeocodeResult

@property(nonatomic, readonly, nullable) NSString *id;
@property(nonatomic, readonly, nonnull) MFLocationComponent *location;
@property(nonatomic, readonly, nonnull) NSString *name;
@property(nonatomic, readonly, nonnull) NSString *address;
@property(nonatomic, readonly, nonnull) NSArray<NSString *> *types;
@property(nonatomic, readonly, nullable) NSArray<id<MFPlaceAddressComponentResult>> *addressComponents;

@end


#endif /* MFGeocodeResult_h */
