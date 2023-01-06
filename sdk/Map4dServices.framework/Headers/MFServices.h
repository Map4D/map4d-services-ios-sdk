//
//  MFServices.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFServices_h
#define MFServices_h

#import "MFServiceTask.h"
#import "MFServiceError.h"
#import "MFServiceRequest.h"
#import "MFServiceSettings.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^MFServicesDataTaskCallback)(NSData * _Nullable data, id<MFServiceError> _Nullable error);

@interface MFServices : NSObject

@property(class, nonatomic, readonly) NSString *version;
@property(class, nonatomic, readonly) MFServiceSettings *settings;

- (id<MFServiceTask>)dataTaskWithRequest:(MFServiceRequest *)request
                       completionHandler:(MFServicesDataTaskCallback)completionHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* MFServices_h */
