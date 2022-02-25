//
//  MFTextSearchParams.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFTextSearchParams_h
#define MFTextSearchParams_h

#import "MFRequestParams.h"
#import "MFLocationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFTextSearchParams : NSObject <MFRequestParams>

/* Text to search */
@property(nonatomic, copy, nonnull) NSString *text;

/* Types to search */
@property(nonatomic, copy, nullable) NSArray<NSString *> *types;

/* Datetime to search */
@property(nonatomic, copy, nullable) NSDate *datetime;

/* The location around which to retrieve place information */
@property(nonatomic, strong, nullable) MFLocationComponent *location;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithText:(NSString *)text;

@end

NS_ASSUME_NONNULL_END

#endif /* MFTextSearchParams_h */
