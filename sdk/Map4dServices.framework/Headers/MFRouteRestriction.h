//
//  MFRouteRestriction.h
//  Map4dServices
//
//  Created by Huy Dang on 1/13/22.
//

#ifndef MFRouteRestriction_h
#define MFRouteRestriction_h

#include "MFLocationComponent.h"
#include "MFViewboxComponent.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MFRouteType) {
  MFRouteTypeMotorway,
  MFRouteTypeTrunk,
  MFRouteTypeFerry,
  MFRouteTypeBridge,
  MFRouteTypeTunnel
};

@interface MFRouteRestriction : NSObject

@property(nonatomic, readonly, nullable) MFLocationComponent *location;

@property(nonatomic, readonly) NSUInteger radius;

@property(nonatomic, readonly, nullable) MFViewboxComponent *viewbox;

@property(nonatomic, readonly, nullable) NSArray<MFLocationComponent *> *path;

- (instancetype)init NS_UNAVAILABLE;

/* Restriction point */
- (instancetype)initWithLocation:(MFLocationComponent *)location;

/* Restriction circle area */
- (instancetype)initWithLocation:(MFLocationComponent *)location radius:(NSUInteger)radius;

/* Restriction rectangle area */
- (instancetype)initWithViewbox:(MFViewboxComponent *)viewbox;

/* Restriction polygon area */
- (instancetype)initWithPath:(NSArray<MFLocationComponent *> *)path;

/* Restriction route type */
- (instancetype)initWithRouteType:(MFRouteType)type;

/* Add route type restriction */
- (void)avoidRouteType:(MFRouteType)type;

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteRestriction_h */
