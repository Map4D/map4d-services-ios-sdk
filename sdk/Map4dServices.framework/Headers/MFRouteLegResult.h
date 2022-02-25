//
//  MFRouteLegResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/29/21.
//

#ifndef MFRouteLegResult_h
#define MFRouteLegResult_h

#import "MFLocationComponent.h"
#import "MFRouteStepResult.h"
#import "MFRouteDescriptionResult.h"

@protocol MFRouteLegResult

@property(nonatomic, readonly, nonnull) NSArray<id<MFRouteStepResult>> *steps;

@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> distance;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> duration;

@property(nonatomic, readonly, nullable) NSString *startAddress;
@property(nonatomic, readonly, nullable) NSString *endAddress;

@property(nonatomic, readonly, nonnull) MFLocationComponent *startLocation;
@property(nonatomic, readonly, nonnull) MFLocationComponent *endLocation;

@end

#endif /* MFRouteLegResult_h */
