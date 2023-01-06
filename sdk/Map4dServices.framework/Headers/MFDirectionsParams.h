//
//  MFDirectionsParams.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFDirectionsParams_h
#define MFDirectionsParams_h

#import "MFRequestParams.h"
#import "MFLocationComponent.h"
#import "MFTravelMode.h"
#import "MFRouteWeighting.h"
#import "MFLanguageResult.h"
#import "MFRouteRestriction.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFDirectionsParams : NSObject <MFRequestParams>

/* Origin location which you wish to calculate directions */
@property(nonatomic, strong, nonnull) MFLocationComponent *origin;

/* Destination location which you wish to calculate directions */
@property(nonatomic, strong, nonnull) MFLocationComponent *destination;

/* Pass through locations between the origin and destination */
@property(nonatomic, copy, nullable) NSArray<MFLocationComponent *> *waypoints;

/* Transportation mode. Default is car */
@property(nonatomic) MFTravelMode mode;

/* The language in which to return results. Default is vietnamese */
@property(nonatomic) MFLanguageResult language;

/* Weighting. Default is fastest */
@property(nonatomic) MFRouteWeighting weighting;

/* Indicates that the calculated route(s) should avoid */
@property(nonatomic, strong, nullable) MFRouteRestriction *restriction;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOrigin:(MFLocationComponent *)origin destination:(MFLocationComponent *)destination;

- (instancetype)initWithOrigin:(MFLocationComponent *)origin
                   destination:(MFLocationComponent *)destination
                          mode:(MFTravelMode)mode
                     weighting:(MFRouteWeighting)weighting;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDirectionsParams_h */
