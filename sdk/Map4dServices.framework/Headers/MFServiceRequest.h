//
//  MFServiceRequest.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFServiceRequest_h
#define MFServiceRequest_h

#import "MFRequestParams.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MFRequestMethod) {
  MFRequestMethodGet,
  MFRequestMethodPost
};

@interface MFServiceRequest : NSObject

/* HTTP request method. Default is GET */
@property(nonatomic) MFRequestMethod method;

/* Default is "https://api.map4d.vn" */
@property(nonatomic, copy, nonnull) NSString *baseURL;

/* Relative path, e.g: "/sdk/autosuggest" */
@property(nonatomic, copy, nullable) NSString *path;

/* HTTP request parameters */
@property(nonatomic, strong, nullable) id<MFRequestParams> params;

/* Request timeout. Default is MFServiceSettings.requestTimeout value */
@property(nonatomic) NSTimeInterval timeout;

- (instancetype)initWithPath:(NSString *)path;

- (instancetype)initWithMethod:(MFRequestMethod)method;

- (instancetype)initWithMethod:(MFRequestMethod)method path:(NSString *)path;

- (NSURLRequest *)asURLRequest;

@end

NS_ASSUME_NONNULL_END

#endif /* MFServiceRequest_h */
