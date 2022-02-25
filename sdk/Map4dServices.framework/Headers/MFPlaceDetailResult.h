//
//  MFPlaceDetailResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/27/21.
//

#ifndef MFPlaceDetailResult_h
#define MFPlaceDetailResult_h

#import "MFLocationComponent.h"
#import "MFPlaceMetadataResult.h"
#import "MFPlacePhotoResult.h"
#import "MFPlaceAddressComponentResult.h"

@protocol MFPlaceDetailResult

@property(nonatomic, readonly, nonnull) NSString *id;
@property(nonatomic, readonly, nonnull) NSString *name;
@property(nonatomic, readonly, nonnull) NSString *address;
@property(nonatomic, readonly, nonnull) MFLocationComponent *location;
@property(nonatomic, readonly, nonnull) NSArray<NSString *> *types;

@property(nonatomic, readonly, nullable) NSString *desc;
@property(nonatomic, readonly, nullable) NSArray<NSString *> *tags;
@property(nonatomic, readonly, nullable) NSArray<id<MFPlaceMetadataResult>> *metadatas;
@property(nonatomic, readonly, nullable) NSArray<id<MFPlacePhotoResult>> *photos;
@property(nonatomic, readonly, nullable) NSArray<id<MFPlaceAddressComponentResult>> *addressComponents;
@property(nonatomic, readonly, nullable) NSString *objectId;

@end


#endif /* MFPlaceDetailResult_h */
