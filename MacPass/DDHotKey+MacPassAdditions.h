//
//  DDHotKey+Coding.h
//  MacPass
//
//  Created by Michael Starke on 25/03/14.
//  Copyright (c) 2014 HicknHack Software GmbH. All rights reserved.
//

#import "DDHotKeyCenter.h"

@interface DDHotKey (MPKeydata)

@property (readonly, copy) NSData *keyData;


/**
 Use this method to retrieve the data, since deallocation of a hotkey unregisters it, this could yield unwanted behaviour!
 @return data for the default hot key.
*/
+ (NSData *)hotKeyDataWithKeyCode:(unsigned short)keyCode modifierFlags:(NSUInteger)flags;
+ (NSData *)defaultHotKeyData;
+ (instancetype)defaultHotKey;
+ (instancetype)defaultHotKeyWithTask:(DDHotKeyTask)task;
+ (instancetype)hotKeyWithKeyData:(NSData *)data task:(DDHotKeyTask)task;
+ (instancetype)hotKeyWithKeyData:(NSData *)data;

@end

@interface DDHotKey (MPValidation)

/*
 A hotkey is considered valid, if the key contains at least a modifier and a non-modifier key.
 For example Control+Alt is no valid hotkey, as it's missing a non-modifier. Control+Escape however is valid.

 @return YES if the hot key is a valid hotkey, NO otherwise
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
