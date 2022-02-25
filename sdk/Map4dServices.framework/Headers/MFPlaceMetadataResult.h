//
//  MFPlaceMetadataResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFPlaceMetadataResult_h
#define MFPlaceMetadataResult_h

#import <Foundation/Foundation.h>

@protocol MFPlaceMetadataResult

@property (nonatomic, readonly, nonnull) NSString *id;
@property (nonatomic, readonly, nonnull) NSString *name;
@property (nonatomic, readonly, nonnull) NSString *type;
@property (nonatomic, readonly, nonnull) NSString *content;
@property (nonatomic, readonly) NSInteger order;

@end


#endif /* MFPlaceMetadataResult_h */
