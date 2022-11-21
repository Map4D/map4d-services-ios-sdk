//
//  MFPlaceMetadataResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
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
