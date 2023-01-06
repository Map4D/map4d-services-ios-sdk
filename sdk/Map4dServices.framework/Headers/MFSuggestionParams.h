//
//  MFSuggestionParams.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFSuggestionParams_h
#define MFSuggestionParams_h

#import "MFRequestParams.h"
#import "MFLocationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFSuggestionParams : NSObject <MFRequestParams>

/** Text is content which to search */
@property(nonatomic, copy, nonnull) NSString *text;

/** The location around which to retrieve place information */
@property(nonatomic, strong, nullable) MFLocationComponent *location;

/** Find acronym, default is NO */
@property(nonatomic) BOOL acronym;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithText:(NSString *)text;

- (instancetype)initWithText:(NSString *)text location:(MFLocationComponent *)location;

- (instancetype)initWithText:(NSString *)text acronym:(BOOL)acronym;

- (instancetype)initWithText:(NSString *)text location:(MFLocationComponent *)location acronym:(BOOL)acronym;

@end

NS_ASSUME_NONNULL_END

#endif /* MFSuggestionParams_h */
