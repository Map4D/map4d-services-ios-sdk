//
//  MFGraphRouteResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFGraphRouteResult_h
#define MFGraphRouteResult_h

#import <CoreLocation/CoreLocation.h>
#import "MFRouteDescriptionResult.h"
#import "MFLocationComponent.h"

@protocol MFGraphRouteResult

@property(nonatomic, readonly, nonnull) NSString *id;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> distance;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> duration;
@property(nonatomic, readonly, nonnull) NSString *encodedPolyline; /* polyline */
//@property(nonatomic, readonly, nonnull) NSString *status;//TODO: status

- (NSArray<MFLocationComponent *> *_Nonnull)polyline;

@end

#endif /* MFGraphRouteResult_h */
