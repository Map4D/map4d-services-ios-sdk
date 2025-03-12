//
//  MFPlacePhotoResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFPlacePhotoResult_h
#define MFPlacePhotoResult_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFPlacePhotoResult : NSObject

@property (nonatomic, readonly) NSString *url;
@property (nonatomic, readonly) NSString *name;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFPlacePhotoResult_h */
