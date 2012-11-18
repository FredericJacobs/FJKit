// FJKeychainUtils.h
//  Storify
//
//  Created by Frederic Jacobs on 1/11/12.
//  Copyright (c) 2012 Frederic Jacobs. All rights reserved.
//

@interface FJKeychainUtils : NSObject

+ (NSString *) getPasswordForUsername: (NSString *) username andServiceName: (NSString *) serviceName error: (NSError **) error;
+ (BOOL) storeUsername: (NSString *) username andPassword: (NSString *) password forServiceName: (NSString *) serviceName updateExisting: (BOOL) updateExisting error: (NSError **) error;
+ (BOOL) deleteItemForUsername: (NSString *) username andServiceName: (NSString *) serviceName error: (NSError **) error;
+ (BOOL) purgeItemsForServiceName:(NSString *) serviceName error: (NSError **) error;

@end