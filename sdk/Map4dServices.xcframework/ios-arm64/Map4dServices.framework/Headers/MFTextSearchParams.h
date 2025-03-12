//
//  MFTextSearchParams.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFTextSearchParams_h
#define MFTextSearchParams_h

#import "MFRequestParams.h"
#import "MFLocationComponent.h"
#import "MFTypeSearchMatching.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFTextSearchParams : NSObject <MFRequestParams>

/* Text to search */
@property(nonatomic, copy, nonnull) NSString *text;

/* Types to search */
@property(nonatomic, copy, nullable) NSArray<NSString *> *types;

/* Matching one of types or all types. Default is All */
@property(nonatomic) MFTypeSearchMatching typeSearchMatching;

/* Datetime to search */
@property(nonatomic, copy, nullable) NSDate *datetime;

/* The location around which to retrieve place information */
@property(nonatomic, strong, nullable) MFLocationComponent *location;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithText:(NSString *)text;

@end

NS_ASSUME_NONNULL_END

#endif /* MFTextSearchParams_h */
