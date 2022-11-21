//
//  MFServiceSettings.h
//  Map4dServices
//
//  Created by Huy Dang on 8/6/22.
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
