//
//  MFPlacePhotoResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFPlacePhotoResult_h
#define MFPlacePhotoResult_h

#import <Foundation/Foundation.h>

@protocol MFPlacePhotoResult

@property (nonatomic, readonly, nonnull) NSString *url;
@property (nonatomic, readonly, nonnull) NSString *name;

@end

#endif /* MFPlacePhotoResult_h */
