//
//  MFGeocodeParams.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFGeocodeParams_h
#define MFGeocodeParams_h

#import "MFRequestParams.h"
#import "MFViewboxComponent.h"
#import "MFLocationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFGeocodeParams : NSObject <MFRequestParams>

/* The location to reverse geocode */
@property(nonatomic, strong, nullable) MFLocationComponent *location;

/* The address to geocode */
@property(nonatomic, copy, nullable) NSString *address;

/* Viewbox location to search */
@property(nonatomic, strong, nullable) MFViewboxComponent *viewbox;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLocation:(MFLocationComponent *)location;

- (instancetype)initWithAddress:(NSString *)address;

@end

NS_ASSUME_NONNULL_END

#endif /* MFGeocodeParams_h */
