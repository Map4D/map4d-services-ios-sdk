//
//  MFPlaceDetailResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFPlaceDetailResult_h
#define MFPlaceDetailResult_h

#import "MFLocationComponent.h"
#import "MFPlaceMetadataResult.h"
#import "MFPlacePhotoResult.h"
#import "MFPlaceAddressComponentResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFPlaceDetailResult : NSObject

@property(nonatomic, readonly) NSString *id;
@property(nonatomic, readonly) NSString *name;
@property(nonatomic, readonly) NSString *address;
@property(nonatomic, readonly) NSString *oldAddress;
@property(nonatomic, readonly) MFLocationComponent *location;
@property(nonatomic, readonly) NSArray<NSString *> *types;

@property(nonatomic, readonly, nullable) NSString *desc;
@property(nonatomic, readonly, nullable) NSArray<NSString *> *tags;
@property(nonatomic, readonly, nullable) NSArray<MFPlaceMetadataResult *> *metadatas;
@property(nonatomic, readonly, nullable) NSArray<MFPlacePhotoResult *> *photos;
@property(nonatomic, readonly, nullable) NSArray<MFPlaceAddressComponentResult *> *addressComponents;
@property(nonatomic, readonly, nullable) NSArray<MFPlaceAddressComponentResult *> *oldAddressComponents;
@property(nonatomic, readonly, nullable) NSString *objectId;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFPlaceDetailResult_h */
