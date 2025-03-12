//
//  MFPlaceMetadataResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFPlaceMetadataResult_h
#define MFPlaceMetadataResult_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFPlaceMetadataResult : NSObject

@property (nonatomic, readonly) NSString *id;
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) NSString *content;
@property (nonatomic, readonly) NSInteger order;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFPlaceMetadataResult_h */
