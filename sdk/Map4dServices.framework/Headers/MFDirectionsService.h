//
//  MFDirectionsService.h
//  Map4dServices
//
//  Created by Huy Dang on 12/29/21.
//

#ifndef MFDirectionsService_h
#define MFDirectionsService_h

#import "MFServiceTask.h"
#import "MFServiceError.h"
#import "MFDirectionsParams.h"
#import "MFDirectionsResult.h"
#import "MFDistanceMatrixParams.h"
#import "MFDistanceMatrixResult.h"
#import "MFGraphRouteParams.h"
#import "MFGraphRouteResult.h"
#import "MFRouteETAParams.h"
#import "MFRouteETAResult.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^MFDirectionsCallback)(MFDirectionsResult *_Nullable directions, id<MFServiceError> _Nullable error);

typedef void(^MFDistanceMatrixCallback)(MFDistanceMatrixResult *_Nullable distanceMatrix, id<MFServiceError> _Nullable error);

typedef void(^MFGraphRouteCallback)(NSArray<MFGraphRouteResult *> *_Nullable graphRoutes, id<MFServiceError> _Nullable error);

typedef void(^MFRouteETACallback)(NSArray<MFRouteETAResult *> *_Nullable etaRoutes, id<MFServiceError> _Nullable error);

@interface MFDirectionsService : NSObject

- (id<MFServiceTask>)fetchDirectionsWithParams:(MFDirectionsParams *)params
                             completionHandler:(MFDirectionsCallback)completionHandler;

- (id<MFServiceTask>)fetchRouteETAWithParams:(MFRouteETAParams *)params
                           completionHandler:(MFRouteETACallback)completionHandler;

- (id<MFServiceTask>)fetchDistanceMatrixWithParams:(MFDistanceMatrixParams *)params
                                 completionHandler:(MFDistanceMatrixCallback)completionHandler;

- (id<MFServiceTask>)fetchGraphRouteWithParams:(MFGraphRouteParams *)params
                             completionHandler:(MFGraphRouteCallback)completionHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDirectionsService_h */
