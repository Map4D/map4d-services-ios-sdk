//
//  MFDirectionsService.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFDirectionsService_h
#define MFDirectionsService_h

#import "MFServiceTask.h"
#import "MFServiceError.h"
#import "MFDirectionsParams.h"
#import "MFDirectionsResult.h"
#import "MFDistanceMatrixParams.h"
#import "MFDistanceMatrixResult.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^MFDirectionsCallback)(MFDirectionsResult *_Nullable directions, id<MFServiceError> _Nullable error);

typedef void(^MFDistanceMatrixCallback)(MFDistanceMatrixResult *_Nullable distanceMatrix, id<MFServiceError> _Nullable error);

@interface MFDirectionsService : NSObject

- (id<MFServiceTask>)fetchDirectionsWithParams:(MFDirectionsParams *)params
                             completionHandler:(MFDirectionsCallback)completionHandler;

- (id<MFServiceTask>)fetchDistanceMatrixWithParams:(MFDistanceMatrixParams *)params
                                 completionHandler:(MFDistanceMatrixCallback)completionHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDirectionsService_h */
