//
//  MPPluginDataViewController.m
//  MacPass
//
//  Created by Michael Starke on 02/02/2017.
//  Copyright © 2017 HicknHack Software GmbH. All rights reserved.
//

#import "MPPluginDataViewController.h"

#import <KeePassKit/KeePassKit.h>

@interface MPPluginDataViewController ()

@property (nonatomic, readonly, assign) KPKNode *representedNode;
@property (strong) NSDictionaryController *pluginDataController;
@property (weak) IBOutlet NSTableView *pluginDataTabelView;

@end

@implementation MPPluginDataViewController

- (NSString *)nibName {
  return @"PluginDataView";
}

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  if(self) {
    _pluginDataController = [[NSDictionaryController alloc] init];
  }
  return self;
}

- (void)didLoadView {
  [self.pluginDataController bind:NSContentDictionaryBinding toObject:self.representedObject withKeyPath:NSStringFromSelector(@selector(customData)) options:nil];
  self.pluginDataTabelView.backgroundColor = [NSColor clearColor];
}

- (KPKNode *)representedNode {
  if([self.representedObject isKindOfClass:[KPKNode class]]) {
    return self.representedObject;
  }
  return nil;
}

- (IBAction)removeAllPluginData:(id)sender {
  //
}

- (NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row {
  NSTableCellView *view = [tableView makeViewWithIdentifier:@"PluginCell" owner:self];
  return view;
}

@end
