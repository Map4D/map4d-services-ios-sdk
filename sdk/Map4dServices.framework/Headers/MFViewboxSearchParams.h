//
//  MFViewboxSearchParams.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFViewboxSearchParams_h
#define MFViewboxSearchParams_h

#import "MFRequestParams.h"
#import "MFViewboxComponent.h"
#import "MFTypeSearchMatching.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFViewboxSearchParams : NSObject <MFRequestParams>

/* Viewbox location to search */
@property(nonatomic, strong, nonnull) MFViewboxComponent *viewbox;

/* Text to search */
@property(nonatomic, copy, nullable) NSString *text;

/* Place types. e.g: holtel, cafe, atm, ... */
@property(nonatomic, copy, nullable) NSArray<NSString *> *types;

/* Matching one of types or all types. Default is All */
@property(nonatomic) MFTypeSearchMatching typeSearchMatching;

/* Place tags */
@property(nonatomic, copy, nullable) NSArray<NSString *> *tags;

/* Datetime to search */
@property(nonatomic, copy, nullable) NSDate *datetime;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithViewbox:(MFViewboxComponent *)viewbox text:(NSString *)text;

- (instancetype)initWithViewbox:(MFViewboxComponent *)viewbox types:(NSArray<NSString *> *)types;

- (instancetype)initWithViewbox:(MFViewboxComponent *)viewbox tags:(NSArray<NSString *> *)tags;

@end

NS_ASSUME_NONNULL_END

#endif /* MFViewboxSearchParams_h */
