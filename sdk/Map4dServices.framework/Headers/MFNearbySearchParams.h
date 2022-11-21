//
//  MFNearbySearchParams.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFNearbySearchParams_h
#define MFNearbySearchParams_h

#import "MFRequestParams.h"
#import "MFLocationComponent.h"
#import "MFTypeSearchMatching.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFNearbySearchParams : NSObject <MFRequestParams>

/* Location */
@property(nonatomic, strong, nonnull) MFLocationComponent *location;

/* Defines the distance (in meters) within which to return place results. The maximum allowed radius is 50000 meters */
@property(nonatomic) NSUInteger radius;

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

- (instancetype)initWithLocation:(MFLocationComponent *)location radius:(NSUInteger)radius text:(NSString *)text;

- (instancetype)initWithLocation:(MFLocationComponent *)location radius:(NSUInteger)radius types:(NSArray<NSString *> *)types;

- (instancetype)initWithLocation:(MFLocationComponent *)location radius:(NSUInteger)radius tags:(NSArray<NSString *> *)tags;

@end

NS_ASSUME_NONNULL_END

#endif /* MFNearbySearchParams_h */
