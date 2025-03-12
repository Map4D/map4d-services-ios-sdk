//
//  MFServiceSettings.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFServiceSettings_h
#define MFServiceSettings_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFServiceSettings : NSObject

/* Request timeout. Default is 10 */
@property(nonatomic) NSTimeInterval requestTimeout;

@end

NS_ASSUME_NONNULL_END

#endif /* MFServiceSettings_h */
