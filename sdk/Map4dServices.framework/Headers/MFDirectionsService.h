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

typedef void(^MFDirectionsCallback)(id<MFDirectionsResult> _Nullable result, id<MFServiceError> _Nullable error);

typedef void(^MFDistanceMatrixCallback)(id<MFDistanceMatrixResult> _Nullable result, id<MFServiceError> _Nullable error);

typedef void(^MFGraphRouteCallback)(NSArray<id<MFGraphRouteResult>> *_Nullable results, id<MFServiceError> _Nullable error);

typedef void(^MFRouteETACallback)(NSArray<id<MFRouteETAResult>> *_Nullable results, id<MFServiceError> _Nullable error);

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
