//
//  MFRouteRestriction.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFRouteRestriction_h
#define MFRouteRestriction_h

#include "MFLocationComponent.h"
#include "MFViewboxComponent.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, MFRouteType) {
  MFRouteTypeNone     = 0,
  MFRouteTypeMotorway = 1U << 0,
  MFRouteTypeTrunk    = 1U << 1,
  MFRouteTypeFerry    = 1U << 2,
  MFRouteTypeBridge   = 1U << 3,
  MFRouteTypeTunnel   = 1U << 4,
  MFRouteTypeToll     = 1U << 5,
};

@interface MFRouteRestriction : NSObject

@property(nonatomic, readonly, nullable) MFLocationComponent *location;

@property(nonatomic, readonly) NSUInteger radius;

@property(nonatomic, readonly, nullable) MFViewboxComponent *viewbox;

@property(nonatomic, readonly, nullable) NSArray<MFLocationComponent *> *path;

@property(nonatomic) MFRouteType routeTypes;

/* Restriction point */
- (instancetype)initWithLocation:(MFLocationComponent *)location;

/* Restriction circle area */
- (instancetype)initWithLocation:(MFLocationComponent *)location radius:(NSUInteger)radius;

/* Restriction rectangle area */
- (instancetype)initWithViewbox:(MFViewboxComponent *)viewbox;

/* Restriction polygon area */
- (instancetype)initWithPath:(NSArray<MFLocationComponent *> *)path;

/* Restriction route types */
- (instancetype)initWithRouteTypes:(MFRouteType)routeTypes;

/* Restriction route type */
- (instancetype)initWithRouteType:(MFRouteType)type DEPRECATED_MSG_ATTRIBUTE("Use common init and set 'routeTypes' instead.");

/* Add route type restriction */
- (void)avoidRouteType:(MFRouteType)type NS_SWIFT_NAME(avoid(_:)) DEPRECATED_MSG_ATTRIBUTE("Set 'routeTypes' instead.");

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteRestriction_h */
