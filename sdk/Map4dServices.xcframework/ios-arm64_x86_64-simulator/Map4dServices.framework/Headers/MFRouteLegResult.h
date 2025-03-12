//
//  MFRouteLegResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFRouteLegResult_h
#define MFRouteLegResult_h

#import "MFLocationComponent.h"
#import "MFRouteStepResult.h"
#import "MFRouteDescriptionResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFRouteLegResult : NSObject

@property(nonatomic, readonly) NSArray<MFRouteStepResult *> *steps;

@property(nonatomic, readonly) MFRouteDescriptionResult *distance;
@property(nonatomic, readonly) MFRouteDescriptionResult *duration;

@property(nonatomic, readonly, nullable) NSString *startAddress;
@property(nonatomic, readonly, nullable) NSString *endAddress;

@property(nonatomic, readonly) MFLocationComponent *startLocation;
@property(nonatomic, readonly) MFLocationComponent *endLocation;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteLegResult_h */
