//
//  MFPlacesService.h
//  Map4dServices
//
//  Created by Huy Dang on 12/27/21.
//

#ifndef MFPlacesService_h
#define MFPlacesService_h

#import "MFServiceTask.h"
#import "MFServiceError.h"
#import "MFSuggestionParams.h"
#import "MFSuggestionResult.h"
#import "MFTextSearchParams.h"
#import "MFNearbySearchParams.h"
#import "MFViewboxSearchParams.h"
#import "MFPlaceResult.h"
#import "MFPlaceDetailResult.h"
#import "MFGeocodeParams.h"
#import "MFGeocodeResult.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^MFSuggestionCallback)(NSArray<MFSuggestionResult *> *_Nullable suggestions, id<MFServiceError> _Nullable error);

typedef void(^MFPlaceDetailCallback)(MFPlaceDetailResult *_Nullable placeDetail, id<MFServiceError> _Nullable error);

typedef void(^MFTextSearchCallback)(NSArray<MFPlaceResult *> *_Nullable places, id<MFServiceError> _Nullable error);

typedef void(^MFNearbySearchCallback)(NSArray<MFPlaceResult *> *_Nullable places, id<MFServiceError> _Nullable error);

typedef void(^MFViewboxSearchCallback)(NSArray<MFPlaceResult *> *_Nullable places, id<MFServiceError> _Nullable error);

typedef void(^MFGeocodeCallback)(NSArray<MFGeocodeResult *> *_Nullable geocodes, id<MFServiceError> _Nullable error);


@interface MFPlacesService : NSObject

- (id<MFServiceTask>)fetchSuggestionWithParams:(MFSuggestionParams *)params
                             completionHandler:(MFSuggestionCallback)completionHandler;

- (id<MFServiceTask>)fetchPlaceDetailWithPlaceId:(NSString *)placeId
                               completionHandler:(MFPlaceDetailCallback)completionHandler;

- (id<MFServiceTask>)searchTextWithParams:(MFTextSearchParams *)params
                        completionHandler:(MFTextSearchCallback)completionHandler;

- (id<MFServiceTask>)searchNearbyWithParams:(MFNearbySearchParams *)params
                          completionHandler:(MFNearbySearchCallback)completionHandler;

- (id<MFServiceTask>)searchViewboxWithParams:(MFViewboxSearchParams *)params
                           completionHandler:(MFViewboxSearchCallback)completionHandler;

- (id<MFServiceTask>)geocodingWithParams:(MFGeocodeParams *)params
                       completionHandler:(MFGeocodeCallback)completionHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* MFPlacesService_h */
