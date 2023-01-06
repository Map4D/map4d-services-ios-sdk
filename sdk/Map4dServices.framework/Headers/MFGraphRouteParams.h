//
//  MFGraphRouteParams.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFGraphRouteParams_h
#define MFGraphRouteParams_h

#import "MFRequestParams.h"
#import "MFLanguageResult.h"
#import "MFTravelMode.h"
#import "MFRouteWeighting.h"
#import "MFLocationComponent.h"
#import "MFRouteRestriction.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFGraphRouteParams : NSObject <MFRequestParams>

@property(nonatomic, copy, nonnull) NSArray<MFLocationComponent *> *locations; /* points */

/* Mode: car or bike or foot or motorcycle. Default is car */
@property(nonatomic) MFTravelMode mode;

/* Default is Vietnamese */
@property(nonatomic) MFLanguageResult language;

/* Default is fastest */
@property(nonatomic) MFRouteWeighting weighting;

/* Indicates that the calculated route(s) graph should avoid */
@property(nonatomic, strong, nullable) MFRouteRestriction *restriction;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLocations:(NSArray<MFLocationComponent *> *)locations;

- (instancetype)initWithLocations:(NSArray<MFLocationComponent *> *)locations mode:(MFTravelMode)mode weighting:(MFRouteWeighting)weighting;

@end

NS_ASSUME_NONNULL_END

#endif /* MFGraphRouteParams_h */
