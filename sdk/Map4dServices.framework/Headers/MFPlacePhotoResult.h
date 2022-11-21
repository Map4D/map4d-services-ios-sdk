//
//  MFPlacePhotoResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
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
