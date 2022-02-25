//
//  MFPlaceAddressComponentResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFPlaceAddressComponentResult_h
#define MFPlaceAddressComponentResult_h

#import <Foundation/Foundation.h>

@protocol MFPlaceAddressComponentResult

@property (nonatomic, readonly, nonnull) NSString *name;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *types;

@end

#endif /* MFPlaceAddressComponentResult_h */
