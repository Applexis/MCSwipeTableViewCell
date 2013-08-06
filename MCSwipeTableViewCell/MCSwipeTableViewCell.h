//
//  MCSwipeTableViewCell.h
//  MCSwipeTableViewCell
//
//  Created by Ali Karagoz on 24/02/13.
//  Copyright (c) 2013 Mad Castle. All rights reserved.
//

@class MCSwipeTableViewCell;

typedef NS_ENUM(NSUInteger, MCSwipeTableViewCellState){
    MCSwipeTableViewCellStateNone = 0,
    MCSwipeTableViewCellState1,
    MCSwipeTableViewCellState2,
    MCSwipeTableViewCellState3,
    MCSwipeTableViewCellState4
};

typedef NS_ENUM(NSUInteger, MCSwipeTableViewCellDirection){
    MCSwipeTableViewCellDirectionLeft = 0,
    MCSwipeTableViewCellDirectionCenter,
    MCSwipeTableViewCellDirectionRight
};

typedef NS_ENUM(NSUInteger, MCSwipeTableViewCellMode){
    MCSwipeTableViewCellModeExit = 0,
    MCSwipeTableViewCellModeSwitch
};

typedef NS_OPTIONS(NSUInteger, MCSwipeGestureDirection) {
    MCSwipeGestureDirectionLeft = 1 << 0,
    MCSwipeGestureDirectionRight = 1 << 1,
};

@protocol MCSwipeTableViewCellDelegate <NSObject>

@optional
- (void)swipeTableViewCell:(MCSwipeTableViewCell *)cell didTriggerState:(MCSwipeTableViewCellState)state withMode:(MCSwipeTableViewCellMode)mode;
- (BOOL)swipeTableViewCell:(MCSwipeTableViewCell *)cell panGestureShouldBegin:(UIPanGestureRecognizer *)gestureRecognizer;

@end

@interface MCSwipeTableViewCell : UITableViewCell

@property(nonatomic, assign) id <MCSwipeTableViewCellDelegate> swipeCellDelegate;

@property(nonatomic, copy) NSString *firstIconName;
@property(nonatomic, copy) NSString *secondIconName;
@property(nonatomic, copy) NSString *thirdIconName;
@property(nonatomic, copy) NSString *fourthIconName;

@property(nonatomic, strong) UIColor *firstColor;
@property(nonatomic, strong) UIColor *secondColor;
@property(nonatomic, strong) UIColor *thirdColor;
@property(nonatomic, strong) UIColor *fourthColor;

@property(nonatomic, assign) MCSwipeTableViewCellMode mode;
@property(nonatomic, assign) BOOL isDragging;
@property(nonatomic, assign) BOOL shouldDrag;

@property(nonatomic, strong, readonly) UIPanGestureRecognizer *panGestureRecognizer;
@property(nonatomic, assign) MCSwipeGestureDirection allowedDirection;

- (id)initWithStyle:(UITableViewCellStyle)style
    reuseIdentifier:(NSString *)reuseIdentifier
 firstStateIconName:(NSString *)firstIconName
         firstColor:(UIColor *)firstColor
secondStateIconName:(NSString *)secondIconName
        secondColor:(UIColor *)secondColor
      thirdIconName:(NSString *)thirdIconName
         thirdColor:(UIColor *)thirdColor
     fourthIconName:(NSString *)fourthIconName
        fourthColor:(UIColor *)fourthColor;

- (void)setFirstStateIconName:(NSString *)firstIconName
                   firstColor:(UIColor *)firstColor
          secondStateIconName:(NSString *)secondIconName
                  secondColor:(UIColor *)secondColor
                thirdIconName:(NSString *)thirdIconName
                   thirdColor:(UIColor *)thirdColor
               fourthIconName:(NSString *)fourthIconName
                  fourthColor:(UIColor *)fourthColor;

@end
