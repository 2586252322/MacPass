//
//  MPPluginVersionInfo.h
//  MacPass
//
//  Created by Michael Starke on 04.10.18.
//  Copyright © 2018 HicknHack Software GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPPluginRepositoryItemVersionInfo : NSObject

- (instancetype)initWithDict:(NSDictionary *)dict NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
