//
//  MFPlaceAddressComponentResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFPlaceAddressComponentResult_h
#define MFPlaceAddressComponentResult_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFPlaceAddressComponentResult : NSObject

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSArray<NSString *> *types;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFPlaceAddressComponentResult_h */
