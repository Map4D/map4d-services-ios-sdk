//
//  MFDistanceMatrixParams.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFDistanceMatrixParams_h
#define MFDistanceMatrixParams_h

#import "MFRequestParams.h"
#import "MFTravelMode.h"
#import "MFLocationComponent.h"
#import "MFRouteWeighting.h"
#import "MFLanguageResult.h"
#import "MFRouteRestriction.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFDistanceMatrixParams : NSObject <MFRequestParams>

/* Origins source, up to 10 location */
@property(nonatomic, readonly, nonnull) NSArray<MFLocationComponent *> *origins;

/* Destinations source, up to 10 location */
@property(nonatomic, readonly, nonnull) NSArray<MFLocationComponent *> *destinations;

/* Mode: car or bike or foot or motorcycle. Default is car */
@property(nonatomic) MFTravelMode mode;

/* Default is vietnamese */
@property(nonatomic) MFLanguageResult language;

/* Weighting. Default is fastest */
@property(nonatomic) MFRouteWeighting weighting;

/* Indicates that the calculated distance matrix should avoid */
@property(nonatomic, strong, nullable) MFRouteRestriction *restriction;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOrigins:(NSArray<MFLocationComponent *> *)origins destinations:(NSArray<MFLocationComponent *> *)destinations;

- (instancetype)initWithOrigins:(NSArray<MFLocationComponent *> *)origins
                   destinations:(NSArray<MFLocationComponent *> *)destinations
                           mode:(MFTravelMode)mode
                      weighting:(MFRouteWeighting)weighting;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDistanceMatrixParams_h */
