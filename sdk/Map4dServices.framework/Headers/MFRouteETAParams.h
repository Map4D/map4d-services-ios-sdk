//
//  MFRouteETAParams.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFRouteETAParams_h
#define MFRouteETAParams_h

#import "MFRequestParams.h"
#import "MFLanguageResult.h"
#import "MFTravelMode.h"
#import "MFRouteWeighting.h"
#import "MFLocationComponent.h"
#import "MFRouteRestriction.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFRouteETAParams : NSObject <MFRequestParams>

/* Origin locations which you wish to calculate ETA */
@property(nonatomic, copy, nonnull) NSArray<MFLocationComponent *> *origins;

/* Destination location which you wish to calculate ETA */
@property(nonatomic, strong, nonnull) MFLocationComponent *destination;

/* Transportation mode. Default is car */
@property(nonatomic) MFTravelMode mode;

/* The language in which to return results. Default is vietnamese */
@property(nonatomic) MFLanguageResult language;

/* Weighting. Default is fastest */
@property(nonatomic) MFRouteWeighting weighting;

/* Indicates that the calculated route(s) should avoid */
@property(nonatomic, strong, nullable) MFRouteRestriction *restriction;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOrigins:(NSArray<MFLocationComponent *> *)origins destination:(MFLocationComponent *)destination;

- (instancetype)initWithOrigins:(NSArray<MFLocationComponent *> *)origins
                    destination:(MFLocationComponent *)destination
                           mode:(MFTravelMode)mode
                      weighting:(MFRouteWeighting)weighting;

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteETAParams_h */
