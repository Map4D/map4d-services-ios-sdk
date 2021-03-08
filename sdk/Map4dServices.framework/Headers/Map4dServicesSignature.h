#ifndef Map4dServicesSignature_h
#define Map4dServicesSignature_h

#import <Foundation/Foundation.h>

@interface Map4dServicesSignature : NSObject

- (instancetype)initWithMode:(NSString*)mode version:(NSString*)version;

- (NSString *)getSignature;

@end

#endif /* Map4dServicesSignature_h */
